
def max(a, b):
    if a > b:
        return a
    return b

def min(a, b):
    if a > b:
        return b
    return a

def getDigits(n):
    return [int(x) for x in str(n)]

def brute(n):
    fill = len(n.split(' ')[0])
    marks = (n).count("?")
    a = b = 0
    dif = -1
    for x in range(10**marks):
        test = n
        number = x
        for i in range(marks):
            digit = number % 10
            test = test.replace("?", str(digit), 1)
            number //= 10
        c, j = test.split(' ')
        c = int(c)
        j = int(j)
        newDif = abs(c - j)
        if (dif == -1 or newDif < dif or (newDif == dif and (c + j < a + b))):
            a = c
            b = j
            dif = newDif
    return str(a).zfill(fill) + " " + str(b).zfill(fill)




def solve(n):
    return brute(n)
    coders, jammers = n.split(' ')
    cval = jval = 0
    for i, l in enumerate(zip(coders, jammers)):
        c, j = l
        tens = 10 ** (len(coders) - i - 1)
        if (c == "?"):
            if (j == "?"): # c = ? j = ?
                if (cval > jval):
                    jval += 9 * tens
                elif jval > cval:
                    cval += 9 * tens
                else:
                    pass # add 0s
            else: #c = ? j = x
                j = int(j)
                jval += j * tens
                if (cval > jval):
                    pass
                elif jval > cval:
                    cval += min(9 * tens, (jval - cval))
                else:
                    cval += j * tens
        else: # c=x
            c = int(c)
            cval += c * tens
            if (j == "?"): #c = x j = ?
                if cval > jval:
                    jval += min(9* tens, (cval - jval))

                elif jval > cval:
                    pass #add 0

                else: # same
                    jval += c * tens
            else:
                j = int(j)
                jval += j * tens


    #print cval, jval
    return str(cval) + " " + str(jval)


def main():
    f = open("input.txt", 'r')
    lines = f.readlines()
    f.close()

    outFile = open("out.txt", 'w')
    for i, n in enumerate(lines[1:]):
        out = "Case #"+str(i + 1)+": " + str(solve(n.replace("\n", "")))+"\n"
        outFile.write(str(out))


main()
