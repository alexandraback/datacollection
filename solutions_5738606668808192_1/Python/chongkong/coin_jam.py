def generate_jam(n, j):
    assert n % 2 == 0
    for i in range(1 << (n//2 - 1), 1 << (n - 1)):
        j -= 1
        seg = str(bin(i))[2:]
        yield seg + seg[::-1]
        if j == 0:
            return


def small():
    print('Case #1:')
    for jam in generate_jam(16, 50):
        print(jam, '3 2 5 2 7 2 9 2 11')


def large():
    print('Case #1:')
    for jam in generate_jam(32, 500):
        print(jam, '3 2 5 2 7 2 9 2 11')


large()