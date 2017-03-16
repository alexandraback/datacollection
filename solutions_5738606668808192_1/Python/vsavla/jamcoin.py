def main():
    t = int(input())
    for i in range(1, t+1):
        nj = input().split()
        print("Case #%d:" % i)
        n, j = int(nj[0]), int(nj[1])
        count = 0
        for num in range(0, 2 ** (n-2)):
            initial = '{0:b}'.format(num)
            initial = '1' + '0' * (n - len(initial) - 2) + initial + '1'
            arr = find_divisors(initial)
            if len(arr) != 0:
                print(initial, *find_divisors(initial))
                count += 1
            if count == j:
                break


def find_divisors(x):
    divisors = []
    for base in range(2, 11):
        base_num = int(x, base=base)
        temp = find_divisor(base_num)
        if temp == -1:
            return []
        else:
            divisors.append(temp)
    return divisors


def find_divisor(x):
    for i in range(2, int(x ** 0.5) + 1):
        if i > 500:
            return -1
        if x % i == 0:
            return i
    return -1

if __name__ == '__main__':
    main()