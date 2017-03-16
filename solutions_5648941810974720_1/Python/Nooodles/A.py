### Google code jam 2016
### Online round 1B
### Problem A

def I(letter):
    return ord(letter)-64;

Cases = int(raw_input());
for i in range(Cases):
    print "Case #%d:" % (i+1),

    Data = [0]*30;
    S = raw_input().split()[0];
    for c in S:
        Data[I(c)] += 1;

    Ans = [0]*10;

    Ans[0] = Data[I('Z')];
    for c in 'ZERO':
        Data[I(c)] -= Ans[0];

    Ans[2] = Data[I('W')];
    for c in 'TWO':
        Data[I(c)] -= Ans[2];

    Ans[4] = Data[I('U')];
    for c in 'FOUR':
        Data[I(c)] -= Ans[4];
        
    Ans[6] = Data[I('X')];
    for c in 'SIX':
        Data[I(c)] -= Ans[6];

    Ans[8] = Data[I('G')];
    for c in 'EIGHT':
        Data[I(c)] -= Ans[8];
        
    Ans[1] = Data[I('O')];
    for c in 'ONE':
        Data[I(c)] -= Ans[1];

    Ans[3] = Data[I('H')];
    for c in 'THREE':
        Data[I(c)] -= Ans[3];

    Ans[5] = Data[I('F')];
    for c in 'FIVE':
        Data[I(c)] -= Ans[5];

    Ans[7] = Data[I('V')];

    Ans[9] = Data[I('I')];

    ANS = '0'*Ans[0] + '1'*Ans[1] + '2'*Ans[2] + '3'*Ans[3] + '4'*Ans[4];
    ANS += '5'*Ans[5] + '6'*Ans[6] + '7'*Ans[7] + '8'*Ans[8] + '9'*Ans[9];        

    print ANS;
        
