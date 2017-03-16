

T = int(input())
count = {'Z': 1, 'O':4, 'W': 1, 'H': 2, 'U':1, 'F': 2, 'X':1, 'S': 2, 'G': 1, 'I':4 }

num = ['Z','O','W','H','U','F','X','S','G','I']

for i in range(1, T+1):
    print("Case #",i,": ",sep="",end="")
    S = input()

    numdict  = {'Z': 0, 'O':0, 'W': 0, 'H': 0, 'U':0, 'F': 0, 'X':0, 'S': 0, 'G': 0, 'I':0 }
    for s in S:
        if numdict.get(s) is not None:
            numdict[s] += 1

    n = [0] * 10


    for i in range(0,10):
        n[i] = numdict[num[i]]
    n[7] = n[7] - n[6]
    n[5] = n[5] - n[4]
    n[3] = n[3] - n[8]
    n[1] = n[1] - n[0] - n[2] - n[4]
    n[9] = n[9] - n[5] - n[6] - n[8]

    ans = ""
    for i in range(0, 10):
        for j in range(0, n[i]):
            ans += str(i)
    print(ans)
