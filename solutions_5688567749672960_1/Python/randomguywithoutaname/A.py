p = [0]*15
p[1] = 10
for i in range(2, 15):
    cnt = p[i-1]
    num = '0'*(i - i/2 - 1) + '9'*(i/2)
    cnt += int(num)
    num = '1' + num
    num = num[::-1]
    cnt += int('9'*i) - int(num) + 1
    p[i] = cnt + 1

#print(p)

def solve(N):
    if (N <= 20):
        return N
    elif int(str(N)[0]) == 1 and int('0' + str(N)[1:len(str(N))/2]) == 0:
        return p[len(str(N)) - 1] + int(str(N)[1:])
    else:
        if int(str(N)[len(str(N))/2:]) == 0:
            return solve(N-1) + 1
        N = str(N)
        return int((N[:len(N)/2])[::-1]) + int(N[len(N)/2:]) + p[len(N) - 1]


T = int(input())
for I in range(1, T+1):
    N = int(input())
    result = solve(N)
    
    print("Case #%d: %d" % (I, result))
    
