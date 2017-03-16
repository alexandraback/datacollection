import sys, string
DEBUG = 0
#reads input from stdin, example usage:
#cat input.txt | s.py > output.txt


def inheritsFrom(child, parent, classes):
    if DEBUG:
        print classes[child]
    if parent in classes[child]:
        return True
    elif classes[child] == []:
        return False
    else:
        for directParent in classes[child]:
            if inheritsFrom(directParent, parent, classes):
                return True
        return False

def traceDiamonds(child, classes, ancestors):
    if DEBUG:
        print ancestors
    for parent in classes[child]:
        if parent in ancestors:
            #seen this one before
            return True
        else:
            #store this one for future check
            ancestors += [parent]
            if traceDiamonds(parent, classes, ancestors):
                return True
    return False;
            
#parse input
try:
    inputlines = sys.stdin.readlines();
except:
    print "Failed to read from standard input, using default case."
    inputlines = ["1","5","2 2 3", "1 4", "1 5", "1 5", "0"]

testcases = int(inputlines[0])
lastline = 1
for T in range(1, testcases+1):
   line = inputlines[lastline]
   N = int(line)
   lastline+=1

   classes = dict()
   for i in range(1, N+1):
       line = string.split(inputlines[lastline])
       lastline+=1
       M = int(line[0])
       classes[i] = []
       for c in line[1:]:
           classes[i] += [int(c)]
   answer = "No"
   for c in classes.keys():
       if traceDiamonds(c, classes, []):
           answer = "Yes"
           break
   print "Case #%d: %s" % (T, answer)
