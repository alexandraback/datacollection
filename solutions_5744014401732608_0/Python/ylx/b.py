from sys import *
f_i = open(argv[1])
f_o = open(argv[2], 'w')
cases = int(f_i.readline() [:-1])
for w in range(1, cases + 1):
    header = 'Case #' + str(w) + ': '
    string = f_i.readline() [:-1]
    bdgs,slides = [int(n) for n in string.split(' ')]
    possible = slides <= 2 ** (bdgs - 2)
    if not possible:
        f_o.write(header + 'IMPOSSIBLE' + '\n')
    else:
        f_o.write(header + 'POSSIBLE' + '\n')
        if bdgs == 2:
            f_o.write('01\n')
            f_o.write('00\n')
        else:
            slides_binary = bin(slides) [2:]
            while len(slides_binary) < bdgs - 2:
                slides_binary = '0' + slides_binary
            f_o.write('0' + slides_binary + '0\n')
            for n in range(2, bdgs + 1):
                f_o.write('0' * n + '1' * (bdgs - n) + '\n')
f_o.close()
