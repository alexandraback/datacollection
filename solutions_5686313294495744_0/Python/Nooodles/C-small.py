### Google code jam 2016
### Online round 1B
### Problem A

def Valid(list1, list2):
    for e in list1:
        if e  not in list2:
            #print 'failed to find ',e
            return False;
    return True


Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    words = int(raw_input());
    Data = [];
    first = [];
    second = [];
    for i in range(words):
        Data.append( raw_input().split() );
        if Data[-1][0] not in first:
            first.append(Data[-1][0]);
        if Data[-1][1] not in second:
            second.append(Data[-1][1]);
    first.sort();
    second.sort();
    
    best = words;
    #print first, second
    for i in range(1,2**words):
        A = bin(i)[2:];
        A = '0'*(words - len(A)) + A;
        real1 = [];
        real2 = [];
        real = 0;
        for c in range(len(A)):
            if A[c] == '1':
                real += 1;
                real1.append(Data[c][0]);
                real2.append(Data[c][1]);

        #print real, real1, real2
        if real < best:
            if Valid(first, real1) and Valid(second, real2):
                best = real;

    print words - best;
        

        
    #   print Data, first, second;
        
