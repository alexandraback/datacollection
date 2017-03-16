
def getdiv(num):
    for i in range(2, 30):
        if num % i == 0:
            return i
    return -1

t = int(input())
n, j = [int(c) for c in input().split()]


cur = 0
print("Case #1:")
for i in range(2 ** (n - 2)):
    s = ('1{0:0' + str(n - 2) + 'b}1').format(i)
    divs = []
    # print()
    for base in range(2, 11):
        exp = 1
        num = 0
        for c in s[::-1]:
            # print(c)
            num += int(c) * exp
            exp *= base
        # print(num, s)
        tmp = getdiv(num)
        if tmp == -1:
            break
        divs.append(tmp)
    if len(divs) == 9:
        print(s, *divs)
        cur += 1
    if cur == j:
        break

