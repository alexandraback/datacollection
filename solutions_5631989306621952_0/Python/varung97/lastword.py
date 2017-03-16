import sys

def lastWord(word):
    ans = word[0]
    for i in word[1:]:
        if i >= ans[0]:
            ans = i + ans
        else:
            ans += i
    return ans

if __name__ == '__main__':
    test = open(sys.argv[1], 'r')
    for i in range(int(test.readline().strip())):
        word = test.readline().strip()
        print('Case #' + str(i + 1) + ': ' + str(lastWord(word)))
