__author__ = 'michal'

import sys
import math

def is_palindrome(num):

    str_num = str(num)
    strlen = len(str_num)

    for i in range(strlen/2):
        if str_num[i] != str_num[-i-1]:
            return False

    return True

def str_square(strnum):

    outdict = {}
    intlist = map(lambda s: int(s), strnum)
    strnumlen = len(strnum)

    for i in reversed(range(strnumlen)):
        to_next = 0

        magic = 0
        for j in reversed(range(strnumlen)):

            magic = strnumlen - 1 - i + strnumlen-1-j

            if magic not in outdict:
                outdict[magic] = 0

            res = intlist[j] * intlist[i] + outdict[magic] + to_next
            to_next = res / 10
            res %= 10

            outdict[magic] = res

        if to_next > 0:
            outdict[magic + 1] = to_next

    out_l = []
    for key in sorted(outdict.keys(), reverse=True):
        out_l.append(str(outdict[key]))

    return "".join(out_l)



def str_lt(a, b):

    if len(a) < len(b):
        return True

    if len(a) > len(b):
        return False

    return a < b

def str_lte(a, b):

    if len(a) < len(b):
        return True

    if len(a) > len(b):
        return False

    return a <= b

def gen_palindromes(digits):

    if digits % 2 == 0:
        center = digits / 2
        odd = False
    else:
        center = digits / 2 + 1
        odd = True


    out = []
    num = 1

    if digits == 1:
        return map(lambda i: str(i), range(0, 10))
    else:
        p = ["1"] + ["0"] * (digits - 2) + ["1"]
    out.append("".join(p))

    stop = False

    while not stop:
        for i in reversed(range(center)):
            digit = int(p[i])

            if (odd and i == center - 1) or i == 0:
                max = 2
            else:
                max = 1

            if digit < max:
                p[i] = str(digit + 1)
                if i != center or not odd:
                    p[digits-1-i] = str(digit + 1)

                out.append("".join(p))
                num += 1
                break

            p[i] = "0"

            if i == 0:
                stop = True
                break

            if i != center or not odd:
                p[digits-1-i] = "0"


    return out

def fair_square(rainbow, rainbow_n, A, B):

    A = str(A)
    B = str(B)

    while (len(rainbow) == 0 or not str_lte(B, rainbow[-1])):
        rainbow_n += 1

        palins = gen_palindromes(rainbow_n)
        for palin in palins:
            sqr_palin  = str_square(palin)
            if is_palindrome(sqr_palin):
                rainbow.append(sqr_palin)


    count = 0
    for palin in rainbow:

        if str_lt(palin, A):
            continue

        if str_lte(palin, B):
            count += 1
        else:
            break

    return (rainbow_n, count)


def parse_and_run():
    file_out = None
    if len(sys.argv) >= 2:
        file = open(sys.argv[1])
        if len(sys.argv) == 3:
            file_out = open(sys.argv[2], 'w')
    else:
        file = sys.stdin

    rainbow = []
    rainbow_n = 0

    cases = int(file.readline())
    for case in range(cases):

        line = file.readline()
        params = map(lambda x: int(x), line.split())

        A = params[0]
        B = params[1]

        assert (B >= A)

        (rainbow_n, result) = fair_square(rainbow, rainbow_n, A, B)

        out = "Case #%i: %s" % (case + 1, result)

        print out
        if file_out != None:
            file_out.write(out + '\n')


if __name__=="__main__":
    parse_and_run()






