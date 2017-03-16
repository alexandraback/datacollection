import math

def readInBase(base, num, length):
    bits = [((num >> bit) & 1) * (base**bit) for bit in range(length)]
    return sum(bits)

def main():
    f = open('out', 'w')
    f.write("Case #1:\n")
    n = 16
    j = 50
    number = 1 | (1<<(n-1))
    while j > 0:
        divList = []
        for i in range(2, 11):
            nInBase = readInBase(i, number, n)
            nontrivialDiv = -1
            for test in range(3, int(math.ceil(math.sqrt(nInBase)))):
                if nInBase % test == 0:
                    nontrivialDiv = test
                    break

            if nontrivialDiv == -1:
                break

            divList.append(nontrivialDiv)


        if len(divList) == 9:
            j -= 1

            bits = [((number >> bit) & 1) for bit in range(n-1, -1, -1)]
            for bit in bits:
                f.write(str(bit))

            for div in divList:
                f.write(" " + str(div))

            f.write('\n')

        number += 2

if __name__ == "__main__":
    main()
