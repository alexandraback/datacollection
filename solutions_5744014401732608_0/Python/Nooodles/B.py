### Google code jam 2016
### Online round 1C
### Problem B

# 1-2
# 1-3
# 2-3
# 1-4
# 2-4
# 3-4

Beg = [0, 0, 1, 0, 1, 2, 0, 1, 2, 3, 0, 1, 2, 3, 4];
End = [1, 2, 2, 3, 3, 3, 4, 4, 4, 4, 5, 5, 5, 5, 5];

def PrintMatrix(B, links):
#    for link in links:
#        print Beg[link], End[link]
#    print links
    
    for i in range(B):
        row = '';
        for j in range(B):
            isOne = False;
            for link in links:
                if (Beg[link] == i) and (End[link] == j):
                    isOne = True;
            if (isOne):
                row += '1';
            else:
                row += '0';
        print row
    return;

def Solutions(B, bridges, target):
    Ends = [];
    for i in range(B):
        Ends.append([]);
    for i in bridges:
        Ends[End[i]].append(Beg[i]);

    Paths = [1];
    for i in range(1, B):
        Paths.append(0);
        for j in Ends[i]:
            Paths[i] += Paths[j];

    if (Paths[-1] == target):
        print "POSSIBLE"
        PrintMatrix(B, bridges);
#        print bridges;
#        for b in bridges:
#            print (Beg[b], End[b]),
        return True;
    return False;
        


def Solve(B, M):
    Bchoose2 = (B*(B-1))/2;
    for i in range(1,2**Bchoose2):
        A = bin(i)[2:];
        A = '0'*(Bchoose2 - len(A)) + A;
        A = A[::-1]

        bridges = [];
        for i in range(Bchoose2):
            if A[i] == '1':
                bridges.append(i);

        if (Solutions(B, bridges, M)):
            return;
    print "IMPOSSIBLE";
  
Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),
    [B, M] = map(int, raw_input().split());
    Solve(B, M);
