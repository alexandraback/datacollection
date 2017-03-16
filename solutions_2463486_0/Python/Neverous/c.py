import sys

def palindrome(word):
    for x in xrange((len(word) + 1) / 2):
        if word[x] != word[-x - 1]:
            return False

    return True

for x in xrange(int(sys.argv[1]), int(sys.argv[2])):
    if palindrome(str(x)):
        y = str(x*x)
        if palindrome(y):
            print y
