fin = file('A-small-attempt3.in', 'r')
fout = file('output.txt', 'w')

t = int(fin.readline())

for i in xrange(t):
    name, n = fin.readline().split()
    n = int(n)
    length = len(name) - 1
    pointer1 = -1
    pointer2 = 0
    result = 0
    subset = 0
    if n == 1 and len(name) == 1:
        result = 1
    else:
        for j in xrange(len(name)):
            if name[j] in ['a', 'e', 'i', 'o', 'u']:
                pointer1 = -1
                pointer2 = 0
            else:
                if pointer1 < 0:
                    pointer1 = j
                pointer2 = j
                if pointer2 - pointer1 + 1 > n:
                    pointer1 += 1
                if pointer2 - pointer1 + 1 == n:
                    diff = length - pointer2
                    if diff > 0:
                        result = result + (pointer1 - subset) + diff + (pointer1 - subset)*diff
                    else:
                        result = result + pointer1 + diff + pointer1*diff - 1
                    if pointer2 - pointer1 != length:
                        result += 1
                    if pointer1 == 0:
                        result -= 1
                    subset = pointer1 + 1
        if result > 0:
            result += 1
    fout.write('Case #' + str(i + 1) + ': ' + str(result) + '\n')
            

fout.close()
