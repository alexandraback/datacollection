

if __name__ == '__main__':
    T = int(input())
    for i in range(1,T+1):
        ans = 'Case #'+str(i)+': '
        N = int(input())
        lN = [float(a) for a in input().split(' ')]
        lK = [float(a) for a in input().split(' ')]
        lN.sort()
        lK.sort()
        lN1 = lN[:]
        lN2 = lN[:]
        lK1 = lK[:]
        lK2 = lK[:]
        Nao = 0
        Ken = 0
        for i in range(N-1,-1,-1):
            if (lN1[i]>lK1[i]):
               lN1.pop()
               lK1.pop()
               Nao += 1
            else:
                lN1.pop(0)
                lK1.pop()
        for i in range(N-1,-1,-1):
            if (lK2[i]>lN2[i]):
                lN2.pop()
                lK2.pop()
                Ken += 1
            else:
                lK2.pop(0)
                lN2.pop()
        Ken = N - Ken
        print(ans+str(Nao)+' '+str(Ken))
