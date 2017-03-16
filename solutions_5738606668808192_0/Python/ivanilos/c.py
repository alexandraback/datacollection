def check(num, N, prime, b_max):
    div = [] # divisor proof
    for base in range(2, b_max + 1):
        counter = 0
        for i in range(0, len(prime)):
            pri = prime[i]
            if pri > base ** (N + 1):
                break
            rem = 0;
            for pot in range(0, N):
                if num[pot] == 1:
                    aux = 1;
                    for p in range(0, pot):
                        aux = (aux * base) % pri
                    rem = (rem + aux) % pri

            #print("base = %d, pri = %d, rem = %d" % (base, pri, rem))
            if rem == 0:
                counter = counter + 1
                if counter >= 2:
                    div.append(pri)
                    break
        if (len(div) < base - 1):
            return []
    return div

def inc(num, N):
    num[1] = num[1] + 1
    for i in range(1, N - 1):
        if num[i] == 2:
            num[i] = 0
            num[i + 1] = num[i + 1] + 1
        else:
            break
    return

def main():
    T = 1
    N = 16
    J = 50
    MAXI = 20000
    B_MAX = 10
    num = [] # number to be tested
    res = [] # coin
    div = [] # divisor proof
    for i in range(0, N):
        if i == 0 or i == N - 1:
            num.append(1)
        else:
            num.append(0)

    prime = []
    is_prime = [1] * MAXI
    for i in range (2, MAXI):
        if is_prime[i] == 1:
            j = i * i
            prime.append(i)
            while(j < MAXI):
                is_prime[j] = 0
                j = j + i

    got = 0
    while got < J and num[N - 1] == 1:
        temp = check(num, N, prime, B_MAX)
        if len(temp) == (B_MAX - 1):
            got = got + 1
            res.append(''.join(str(e) for e in reversed(num)))
            div.append(temp)
        inc(num, N)

    print("Case #1:")
    for i in range(0, J):
        print(res[i], end="")
        for j in range(0, B_MAX - 1):
            print(" %d" % div[i][j], end ="")
        print("") # print newline

    return 0

if __name__ == '__main__':
   main()
