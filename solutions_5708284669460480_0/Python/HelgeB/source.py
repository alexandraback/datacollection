import random

path = "C:/Users/Helge/Downloads/"
filename = "B-small-attempt0.in"
input_file = open(path+filename, 'r')
output = open(path + 'output', 'w')

numberOfTestcases = input_file.readline()
def readLineList():
    return input_file.readline().replace('\n', '').split(' ')

def writeOut(s, count):
    s = 'Case #' + str(count+1) + ': ' + s
    print(s)
    output.write(s + '\n')  

def getOverlap(s):
    over = 0
    for i in range(1,len(s)):
        if s[:i]==s[-i:]:
            over=i
    return over
    
def possible(target, keys):
    for s in target:
        if not s in keys:
            return False
    return True
    
def getMaxBananas(target, S, keys):
    if not possible(target, keys):
        return 0
    overlap = getOverlap(target)
    l = len(target)
    return int((S-l)/(l-overlap))+1

def doTyping(keys,S):
    result = ''
    for i in range(0,S):
        result += random.choice(keys)
    return result 

def checkHits(typed,target):
    hits = 0
    for i in range(0,len(typed)):
        end = i+len(target)
        if end <= len(typed) and typed[i:end] == target:
            hits += 1
    return hits

def simHits(keys,target,S):
    typed = doTyping(keys,S)
    return checkHits(typed,target)

def getAvHits(keys,target,S):
    simulations = 100000
    hits = 0
    for i in range(0,simulations):
        hits += simHits(keys,target,S)
    return hits/simulations
   
for i in range(0, int(numberOfTestcases)):
    [K,L,S] = list(map(int,readLineList()))
    keys = input_file.readline().replace('\n', '')
    target = input_file.readline().replace('\n', '')
    
    maxBananas = getMaxBananas(target, S, keys)
    avHits = getAvHits(keys,target,S)
    
    result = str(maxBananas-avHits)
    writeOut(str(result),i)

output.close()