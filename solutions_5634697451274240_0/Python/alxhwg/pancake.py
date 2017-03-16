import sys
import string

def main():
    tests = ["-", "-+", "+-", "+++", "--+-"]
    # for test in tests:
    #     print(minPancake(test))[0]
    inF = open(sys.argv[1], 'r')
    name = string.split(sys.argv[1], '.', 1)[0]
    ouF = open("{0}Out.txt".format(name), 'w')
    T = int(inF.readline())
    for i in range(T):
        S = inF.readline()
        n = minPancake(S[:-1])
        ouF.write("Case #{0}: {1}\n".format(i+1, n))
    inF.close()
    ouF.close()


def minPancake(pancakeStr):
    flips = 0
    signs = {0: "+", 1: "-"}
    sign = pancakeStr[0]
    if sign == "+":
        i = 0
    else:
        i = 1
    for char in pancakeStr[1:]:
        if char != signs[i]:
            flips += 1
            i = 1 - i
    if signs[i] == "-":
        flips += 1
    return flips

if __name__ == '__main__':
  main()
