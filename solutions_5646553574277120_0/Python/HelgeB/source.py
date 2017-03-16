import random
import itertools

path = "C:/Users/Helge/Downloads/"
filename = "C-small-attempt1.in"
input_file = open(path+filename, 'r')
output = open(path + 'output', 'w')

numberOfTestcases = input_file.readline()
def readLineList():
    return input_file.readline().replace('\n', '').split(' ')

def writeOut(s, count):
    s = 'Case #' + str(count+1) + ': ' + s
    print(s)
    output.write(s + '\n')  

def allSubs(lst):
    result = []
    for i in range(1,len(lst)+1):
        result.extend(list(itertools.combinations(lst, i)))
    return result

def isPossible(n,den,V):
    n = list(n)
    coins = n + den
    subs = map(sum,allSubs(coins))
    subs = [x for x in subs if x<=V]
    return len(set(subs))==V
    
def possible(den, V, i):
    allCoins = set(range(1,V+1))
    allCoins = list(allCoins.difference(set(den)))
    newCoins = list(itertools.combinations(allCoins, i))
    for n in newCoins:
        if isPossible(n,den,V):
            return True
    return False
    
def getMin(den,V):
    i = 0
    while not possible(den, V, i):
        i += 1
        if i > V:
            return -1
    return i
    
for i in range(0, int(numberOfTestcases)):
    [C,D,V] = list(map(int,readLineList()))
    den = list(map(int,readLineList()))
    
    result = str(getMin(den,V))
    writeOut(str(result),i)

output.close()