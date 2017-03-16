FILENAME = "A-small-attempt0"
INPUTFILE = FILENAME + ".in"
OUTPUTFILE = FILENAME + ".out"
LINE_PER_CASE = 1

inputfile = open(INPUTFILE, 'r')
outputfile = open(OUTPUTFILE, 'w')
NUMCASE = int(inputfile.readline())

class TestCase:
    def find_num_line(self):
        if LINE_PER_CASE:
            return LINE_PER_CASE
        else:
            """
            depends on the situation, may vary
            """
            line = inputfile.readline()
            return
    
    def takeInput(self, content):
        """
        content is a list of lines,
        parse the input to my variables needed
        """
        self.n = int(content[0])
    
    def returnOutput(self):
        """
        deal with self.answer, it is a tuple, or a single
        """
        if self.answer != 0:
            result = str(self.answer)
        else:
            result = "INSOMNIA"
        return result
    
    def compute(self):
        """
        using variables parse (self.variable1, self.variable2, blablabla
        call the function that actually solve the problem
        put it in self.answer as a tuple or a single value 
        """
        self.answer = start_counting(self.n)
        
        
"""
-----------------------------------------------------------------
now is function time~
"""

def list_digit(n):
    digit_set = set()
    digit_set.add(n%10)
    n = n //10
    while n > 0:
        digit_set.add(n % 10)
        n = n//10
    return digit_set

def start_counting(n):
    digit_saw = set()
    for i in range(10000):
        digit_list = list_digit(n*(i+1))
        digit_saw = digit_saw.union(digit_list)   
        if len(digit_saw) == 10:
            return n*(i+1)
    return 0
    
    
    
for caseindex in range(NUMCASE):
    print("Case #" + str(caseindex+1) + " input: ")
    testcase = TestCase()
    content = []
    num_line = testcase.find_num_line()
    for lineindex in range(num_line):
        line = inputfile.readline()
        content.append(line)
        print(line)  
    testcase.takeInput(content)
    testcase.compute()
    result = testcase.returnOutput()
    result = "Case #" + str(caseindex+1) + ": " + result + "\n"
    print(result)
    outputfile.write(result)
outputfile.close()   
inputfile.close()