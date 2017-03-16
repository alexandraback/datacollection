# import necessary modules

# global variables
n = 0
string = ''

vowels = ['a', 'e', 'i', 'o', 'u']
# helper functions
def isconsecutive(string):
    for i in range(n - 1):
        if string [i] in vowels:
            return False
    return True

def isnsubstring(string):
    for i in range(len(string) - n + 1):
        if string [i] not in vowels:
            if isconsecutive(string [i + 1:]):
                return True
    return False

def calculateleft(string):
    global result
    if len(string) < n:
        return
    if isnsubstring(string):
        result += 1
    calculateleft(string[:-1])

def calculateright(string):
    global result
    if len(string) < n:
        return
    if isnsubstring(string):
        result += 1
    calculateleft(string[:-1])
    calculateright(string[1:])

# read function
def read():
    global string, n, result
    result = 0
    temp = raw_input()
    loc = temp.find(' ')
    string = temp[:loc]
    n = int(temp[loc + 1:])

# main logic
def solve(i):
    read()
    calculateright(string)
    print 'Case #' + str(i) + ': ' + str(result)

def main():
    T = int(raw_input())
    for i in range(T):
        solve(i + 1)

main()
