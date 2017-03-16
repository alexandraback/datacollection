from enum import Enum

class Quaternion(Enum):
    (ONE, I, J, K) = range(4)


def multiply(quat1, quat2):
    sgn1, base1 = quat1
    sgn2, base2 = quat2

    if base1 == Quaternion.ONE:
        sgn3 = 1
        new_base = base2

    elif base2 == Quaternion.ONE:
        sgn3 = 1
        new_base = base1

    elif base1 == base2:
        sgn3 = -1
        new_base = Quaternion.ONE

    elif base1 == Quaternion.I and base2 == Quaternion.J:
        sgn3 = 1
        new_base = Quaternion.K

    elif base1 == Quaternion.J and base2 == Quaternion.K:
        sgn3 = 1
        new_base = Quaternion.I

    elif base1 == Quaternion.K and base2 == Quaternion.I:
        sgn3 = 1
        new_base = Quaternion.J

    elif base1 == Quaternion.I and base2 == Quaternion.K:
        sgn3 = -1
        new_base = Quaternion.J

    elif base1 == Quaternion.K and base2 == Quaternion.J:
        sgn3 = -1
        new_base = Quaternion.I

    elif base1 == Quaternion.J and base2 == Quaternion.I:
        sgn3 = -1
        new_base = Quaternion.K

    return (sgn1 * sgn2 * sgn3, new_base)


with open("C-small-attempt0.in") as infile:
    with open("C.out", "w") as outfile:
        ncases = int(next(infile))

        for case in range(1, ncases+1):
            L, X = map(int, next(infile).split())
            string = next(infile).rstrip()

            curr = (1, Quaternion.ONE)
            i_check = False
            k_check = False

            for c in string * X:
                mul = {"i": (1, Quaternion.I), "j": (1, Quaternion.J), "k": (1, Quaternion.K)}[c]

                curr = multiply(curr, mul)

                if not i_check and curr == (1, Quaternion.I):
                    i_check = True

                if i_check and not k_check and curr == (1, Quaternion.K):
                    k_check = True

            if i_check and k_check and curr == (-1, Quaternion.ONE):
                result = "YES"

            else:
                result = "NO"

            print("Case #{}: {}".format(case, result), file=outfile)
            
