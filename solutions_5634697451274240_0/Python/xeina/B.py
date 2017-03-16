FILENAME = "B-small-attempt0"
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
        self.pancakes = content[0].strip()
    
    def returnOutput(self):
        """
        deal with self.answer, it is a tuple, or a single
        """
        result = str(self.answer)
        return result
    
    def compute(self):
        """
        using variables parse (self.variable1, self.variable2, blablabla
        call the function that actually solve the problem
        put it in self.answer as a tuple or a single value 
        """
        clean_pancakes = clear_pancakes(self.pancakes)
        print(clean_pancakes)
        self.answer = count_flip(clean_pancakes)
        
        
"""
-----------------------------------------------------------------
now is function time~
"""


def clear_pancakes(pancakes):
    cur = '0'
    new_pancakes = ''
    for pancake in pancakes:
        if pancake != cur:
            new_pancakes += pancake
            cur = pancake
    return new_pancakes

def count_flip(cleared_pancakes):
    if cleared_pancakes[-1] == '+':
        return len(cleared_pancakes) - 1
    else:
        return len(cleared_pancakes)
            

        
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