def main():
    t = int(input())
    for i in range(1, t+1):
        nj = input().split()
        print("Case #%d:" % i)
        n, j = int(nj[0]), int(nj[1])
        count = 0
        for num in range(2 ** (n-1), 2 ** n):
            if num % 2 == 0:
                continue
            initial = '{0:b}'.format(num)
            initial = '0' * (n - len(initial)) + initial
            divisors = []
            for base in range(2, 11):
                base_num = int(initial, base=base)
                temp = find_divisor(base_num)
                if temp == -1:
                    break
                else:
                    divisors.append(temp)
            if len(divisors) == 9:
                count += 1
                print(initial, end=' ')
                for divisor in divisors[:-1]:
                    print(divisor, end=' ')
                print(divisors[-1])
            if count == j:
                break


def find_divisor(x):
    for i in range(2, int(x ** 0.5) + 1):
        if x % i == 0:
            return i
    return -1

if __name__ == '__main__':
    main()