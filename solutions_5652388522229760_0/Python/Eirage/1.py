file = open('A-small-attempt0.in', 'r')
out = open('result.out','w')
T = int(file.readline())
print(T)

for k in range (T):
    N = int(file.readline())
    if N == 0:
        out.write('Case #' + str(k+1) + ': INSOMNIA\n')
    else:
        dic ={}
        i = 1
        while len(dic)!=10:
            n = i * N
            while n > 0:
                g = n % 10
                n = n // 10
                dic[g] = 1
            print(dic)
            i += 1
        print(N*(i-1))
        out.write('Case #' + str(k+1) + ': '+str(N*(i-1))+'\n')
out.close()

