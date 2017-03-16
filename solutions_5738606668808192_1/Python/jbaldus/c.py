def get_divisor(i):
    for j in range(2, min(1000, i - 1)):
        if i % j == 0:
            return j
    return 1

def solve():
    inpul_values = input().split()
    n = int(inpul_values[0])
    j = int(inpul_values[1])

    coin = (1 << (n - 1)) + 1;
    cnt = 0

    while cnt < j:
        if coin >= (1 << n):
            print("failure")
            break

        divs = []
        is_coin = True
        for base in range(2, 11):
            number = 0
            x = 1
            for i in range (0, n):
                if (coin // (1 << i)) % 2:
                    number += x
                x *= base

            d = get_divisor(number)
            divs.append(str(d))
            if d == 1:
                is_coin = False
                break

        if is_coin:
            cnt += 1
            print(bin(coin)[2:], " ".join(divs))

        coin += 2

input()
print("Case #1: ")
solve()
