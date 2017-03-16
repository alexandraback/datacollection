FILENAME = "A-large"
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
        self.S = content[0].strip()
        
    
    def returnOutput(self):
        """
        deal with self.answer, it is a tuple, or a single
        """
        result = self.answer
        return result
    
    def compute(self):
        """
        using variables parse (self.variable1, self.variable2, blablabla
        call the function that actually solve the problem
        put it in self.answer as a tuple or a single value 
        """
        self.answer = create_word(self.S)
        
        
"""
-----------------------------------------------------------------
now is function time~
"""

def create_word(starting_string):
    new_string = starting_string[0]
    starting_string = starting_string[1:]
    for char in starting_string:
        if char < new_string[0]:
            new_string = new_string+char
        else:
            new_string = char + new_string
    return new_string



        
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