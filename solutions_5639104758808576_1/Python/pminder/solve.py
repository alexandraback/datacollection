#coding:utf8

def solve():
    Smax, p = input().split(' ')
    n = 0
    result = 0

    for i in range(int(Smax) + 1):
        if n < i:
            result += 1
            n += 1
        n += int(p[i])

    return result

if __name__ == '__main__':
    T = int(input())

    for i in range(T):
        result = solve()
        print("Case #{}: {}".format(i+1, result))
