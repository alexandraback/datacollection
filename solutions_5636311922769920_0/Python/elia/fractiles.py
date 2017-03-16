
import string
import math


def main():

    test_case = int(raw_input())
    for i in range(0, test_case):

        str_input = raw_input()
        k, c, s = map(int, str_input.split())

        found = 0
        elements = []

        if s < math.ceil(float(k)/c):
            print "Case #"+str(i+1)+": IMPOSSIBLE"

        else:
            while found < k:
                n = k**c
                index = 0
                for l in range(0, c):
                    n /= k
                    index += found*n
                    found += 1
                    if found == k:
                        break
                elements.append(index+1)

            result = [" " + str(x) for x in elements]
            print "Case #"+str(i+1)+":" + string.join(result)


if __name__ == "__main__":
    main()
