from bitarray import bitarray


def str_to_bit(cakes):
    cakes = cakes.replace('+', '1')
    cakes = cakes.replace('-', '0')
    return bitarray(cakes)


def upside(cakes):
    N = len(cakes)
    res = bitarray(N)
    for i in range(N):
        res[i] = not cakes[N - i - 1]
    return res


def negate(cakes):
    return bitarray([not x for x in cakes])


def min_flips_wrong(cakes_bit):
    flips = 0
    ready = False
    while len(cakes_bit) > 0 and len(cakes_bit) != sum(cakes_bit):
        if cakes_bit[-1] == True:
            cakes_bit.pop()
        else:
            cakes_bit.pop()
            cakes_bit = negate(cakes_bit)
            flips += 1
    return flips


def min_flips(cakes_bit):
    reduced_cakes = bitarray()
    reduced_cakes.append(cakes_bit[0])
    for x in cakes_bit[1:]:
        if x != reduced_cakes[len(reduced_cakes)-1]:
            reduced_cakes.append(x)
    res = len(reduced_cakes)
    if reduced_cakes.pop() == True:
        res -= 1
    return res



f = open("C://Users//Pavlo//Downloads//B-large.in")
f_out = open("C://Users//Pavlo//Downloads//cakes_out.txt", "a")
T = int(f.readline())
print(T)
for i in range(T):
    cakes = f.readline()
    if cakes[-1].isspace():
        cakes_bit = str_to_bit(cakes[:-1])
    else:
        cakes_bit = str_to_bit(cakes)
    res = min_flips(cakes_bit)
    f_out.write("Case #" + str(i + 1) + ": " + str(res) + "\n")
    print("Case #" + str(i + 1) + ": " + str(res) + "\n")

'''
x = str_to_bit("-+-")
print(x)
y = upside(x)
print(sum(y))
print(y[1])
'''
