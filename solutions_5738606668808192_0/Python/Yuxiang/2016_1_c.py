# Problem C. Coin Jam


def to_int(l, base):
    res = 0
    scale = 1
    for val in l[::-1]:
        res += scale * int(val)
        scale *= base
    return res
    

t = int(input())
n, j = map(int, input().split(' '))

print("Case #{}:".format(1))
magic = [0 for i in range(n // 2 + 1)]
magic[0] = 1
magic[-1] = 1
diviser = ' '.join(map(str, [to_int(magic, i) for i in range(2, 11)]))

for i in range(j):
    piece = bin(i)[2:]
    res = [0 for i in range(n)]
    res[0] = 1
    res[n // 2 - 1] = 1
    res[n // 2] = 1
    res[n - 1] = 1
    res[n // 2 - 1 - len(piece): n // 2 - 1] = piece
    res[n- 1 - len(piece): n - 1] = piece
    print(''.join(map(str, res)) + ' ' + diviser)
