import random

def counting(n, _):
    if n == 0:
        return 'CASE #%d: INSOMNIA' % _
    digits = set()
    x = 1
    while len(digits) < 10:
        for d in set(str(x * n)):
            digits.add(d)
        x += 1
    return 'CASE #%d: %d' % (_, (x - 1) * n)

def main():
    for _ in range(int(input())):
        print(counting(int(input()), _ + 1))

def test():
    for _ in range(1, 101):
        print(counting(random.choice(range(10 ** 5, 10 ** 6 + 1)), _))

if __name__ == '__main__':
    main()
