### Google code jam 2016
### Online round 1B
### Problem A

def I(letter):
    return ord(letter)-64;

def D(s1, s2):
    return abs(int(s1)-int(s2));

def Deviation(one, two):
    for d in range(len(one)):
        if ('?' != one[d] != two[d] != '?'):
            return d;
    return -1;   

def Equality(one, two):
    ans = '';
    for d in range(len(one)):
        if one[d] == two[d] == '?':
            ans += '0';
        if one[d] != '?' and two[d] == '?':
            ans += One[d];
        if one[d] == '?' and two[d] != '?':
            ans += Two[d];
        if one[d] != '?' and two[d] != '?':
            ans += one[d];
    return ans;

def FindBest(data):
    best = 1e25;
    for row in data:
        if D(row[0], row[1]) < best:
            best = D(row[0], row[1]);
            bestO = row[0];
            bestR = row[1];
        if D(row[0], row[1]) == best and row[0] < bestO:
            bestO = row[0];
            bestR = row[1];
        if D(row[0], row[1]) == best and row[0] == bestO and row[1] < bestR:
            bestO = row[0];
            bestR = row[1];

    print bestO, bestR

def MAX(s):
    return s.replace('?','9');
def MIN(s):
    return s.replace('?','0');

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),
    [One, Two] = raw_input().split();

    minOne = int(One.replace('?', '0'));
    minTwo = int(Two.replace('?', '0'));
    
    ANS = [];
    dev = Deviation(One, Two);
    if (dev == -1):
        both = Equality(One, Two);
        print both, both
    else:
        common = Equality(One[:dev], Two[:dev]);
        minO = common + One[dev:].replace('?','0');
        maxT = common + Two[dev:].replace('?', '9');

        maxO = common + One[dev:].replace('?', '9');
        minT = common + Two[dev:].replace('?','0');

        ANS.append( [minO, maxT] );
        ANS.append( [maxO, minT] );

        while (dev > 0):
            dev -= 1;
            if (One[dev] == '?'):
 #               print dev, One, Two
                if Two[dev] not in ['0', '?']:
                    newOne = MIN(One[:dev]) + str(int(Two[dev]) - 1) + MAX(One[dev+1:]);
                    ANS.append( [newOne, minT] );
                    ANS.append( [newOne, maxT] );
                if Two[dev] not in ['9', '?']:
                    newOne = MIN(One[:dev]) + str(int(Two[dev]) + 1) + MIN(One[dev+1:]);
                    ANS.append( [newOne, minT] );
                    ANS.append( [newOne, maxT] );

            if (Two[dev] == '?'):
                if One[dev] not in ['0', '?']:
                    newTwo = MIN(Two[:dev]) + str(int(One[dev]) - 1) + MAX(Two[dev+1:]);
                    ANS.append( [minO, newTwo] );
                    ANS.append( [maxO, newTwo] );
                if One[dev] not in ['9', '?']:
                    newTwo = MIN(Two[:dev]) + str(int(One[dev]) + 1) + MIN(Two[dev+1:]);
                    ANS.append( [minO, newTwo] );
                    ANS.append( [maxO, newTwo] );

            if (One[dev] == Two[dev] == '?'):
#                print 'meep'
                newOne = MIN(minO[:dev]) + '1' + MIN(One[dev+1:]);
                newTwo = MIN(minT[:dev]) + '0' + MAX(Two[dev+1:]);
#                print newOne, newTwo
                ANS.append([newOne, newTwo]);
               
                newOne = MIN(minO[:dev]) + '0' + MAX(One[dev+1:]);
                newTwo = MIN(minT[:dev]) + '1' + MIN(Two[dev+1:]);

                ANS.append([newOne, newTwo]);
        
        FindBest(ANS);
        
