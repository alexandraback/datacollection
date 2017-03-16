import math

def custom_range(start=0,stop=None,step=1):
    '''xrange in python 2.7 fails on numbers larger than C longs.
    we write a custom version'''
    if stop is None:
        #handle single argument case. ugly...
        stop = start
        start = 0
    i = start
    while i < stop:
        yield i
        i += step
xrange=custom_range

def readInBase(base, num, length):
    bits = [((num >> bit) & 1) * (base**bit) for bit in range(length)]
    return sum(bits)

def main():
    f = open('out', 'w')
    f.write("Case #1:\n")
    n = 32
    j = 500
    numbers = [1+base**(n-1) for base in range(2, 11)]
    while j > 0:
        divList = []
        for testNum in numbers:
            nontrivialDiv = -1
            for testDiv in xrange(3, 3000):
                if testNum % testDiv == 0:
                    nontrivialDiv = testDiv
                    break

            if nontrivialDiv == -1:
                break

            divList.append(nontrivialDiv)


        if len(divList) == 9:
            j -= 1

            f.write(str(numbers[-1]))

            for div in divList:
                f.write(" " + str(div))

            f.write('\n')

        numbers[0] += 2
        for idx in range(1, len(numbers)):
            numbers[idx] = readInBase(idx+2, numbers[0], n)

if __name__ == "__main__":
    main()
