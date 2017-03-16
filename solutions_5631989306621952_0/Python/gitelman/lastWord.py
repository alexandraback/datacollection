


def getLastWord(S):
    toReturn = ""
    for c in S:

        if not toReturn:
            toReturn = c
        elif c >= toReturn[0]:
            toReturn = c + toReturn
        else:
            toReturn = toReturn + c

    return toReturn

def main():
    T = int(raw_input())
    for i in range(1, T+1):
        currString = raw_input()
        print "Case #{}: {}".format(i, getLastWord(currString))

if __name__ == "__main__":
    main()