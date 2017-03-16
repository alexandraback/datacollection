import itertools

N = 16
J = 50


def isprime(n):
    if n == 2:
        return -1

    if not n & 1:
        return 2

    for x in range(3, int(n**0.5) + 1, 2):
        if n % x == 0:
            return x

    return -1

with open("data1.txt", 'w') as g:
    counter = 0
    g.write("Case #1: \n")
    for j in list(itertools.product([0, 1], repeat=(N-2))):

        jamcoin = list(j)
        jamcoin.insert(0, 1)
        jamcoin.append(1)
        jamcoin.reverse()

        isFail = False
        divisors = []
        for base in range(2, 11):
            num = 0
            for i in range(N):
                num += jamcoin[i]*(base**i)
            test = isprime(num)
            if test == -1:
                isFail = True
                break
            else:
                divisors.append(test)

        if isFail:
            continue

        print jamcoin, divisors

        jamcoin.reverse()

        strjam = "".join([str(x) for x in jamcoin]) + " "
        output = strjam + " ".join([str(x) for x in divisors])
        g.write(output + "\n")

        counter += 1
        if counter == J:
            break