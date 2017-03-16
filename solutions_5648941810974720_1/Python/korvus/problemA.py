from pprint import pprint as pp 
from collections import defaultdict

numbers = {
    0:"ZERO", # only Z, 1/3 Rs
    1:"ONE",
    2:"TWO", # only W
    3:"THREE", # 1/2 H
    4:"FOUR", # only U, 1/2 F
    5:"FIVE", # 1/2 F
    6:"SIX", # only X
    7:"SEVEN", 
    8:"EIGHT", # only G, 1/2 H
    9:"NINE"
}

numbersCharCount = {}
for k,v in numbers.items():
    numbersCharCount[k] = defaultdict(int)
    for ch in v:
        numbersCharCount[k][ch] = numbersCharCount[k][ch]+1
    #print "numbersCharCount"
    #pp(numbersCharCount)



num_cases = int(raw_input())  # read a line with a single integer
    
for casenum in xrange(num_cases):
    chars = raw_input()
    ###
    numbersOut = []
    charCount = defaultdict(int)
    for char in chars:
        charCount[char] = charCount[char]+1
    #print "charCount for "+chars
    #pp(charCount)
    for num in [0,2,4,6,8,  1,3,5,7,9]: #range(10):
        curChars = numbers[num]
        curCharCount = numbersCharCount[num]
        #while all((ch in chars))
        #print "testing: "
        
        #pp([charCount[char] >= count for char,count in curCharCount.items()])
        while all((charCount[char] >= count for char,count in curCharCount.items())):
            numbersOut.append(num)
            for char,count in curCharCount.items():
                charCount[char] = charCount[char] - count
    ###
    print "Case #{}: {}".format(casenum+1, "".join([str(n) for n in sorted(numbersOut)]))
