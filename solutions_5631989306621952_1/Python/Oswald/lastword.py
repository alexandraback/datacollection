'''
STACKOVERFLOW CODE USED FROM
http://stackoverflow.com/questions/522372/finding-first-and-last-index-of-some-value-in-a-list-in-python
http://stackoverflow.com/questions/4528982/convert-alphabet-letters-to-number-in-python
http://stackoverflow.com/questions/18544419/how-to-convert-numbers-to-alphabet-in-python
'''

def getIndexOfHighestLast(word):
    highest = max(word)
    return len(word) - 1 - word[::-1].index(highest)

def getSmallWord(word):
    startIndex = getIndexOfHighestLast(word)
    start = word[startIndex]
    end = word[startIndex+1:]
    middle = word[:startIndex]
    return (start, middle, end)

def main():
    cases = int(raw_input())
    for case in range(1, cases + 1):
        #do stuff
        base = raw_input()
        word = [ord(char) - 96 for char in base.lower()]
        start = ""
        end = []
        while len(word) > 0:
            theStart, theMiddle, theEnd = getSmallWord(word)
            start = start + chr(theStart - 1 + ord('a'))
            word = theMiddle
            theEnd.extend(end)
            end = theEnd
        for x in end:
            start = start + chr(x - 1 + ord('a'))
        start = start.upper()
        print "CASE #%s: %s" % (case, start)

main()