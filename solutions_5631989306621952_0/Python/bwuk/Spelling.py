#spelling game


def GetLastWord(s):
    result = ""

    for c in s:
        if len(result) == 0:
            result = str(c)
        elif result[0] <= c:
            result = str(c) + result
        else:
            result += str(c)

    return result

def main():
    f = open("string.in", "r")
    numCases = int(f.readline())

    for i in range(1, numCases+1):
        word = f.readline().strip()
        print("Case #", i, ": ", GetLastWord(word), sep='')

main()
