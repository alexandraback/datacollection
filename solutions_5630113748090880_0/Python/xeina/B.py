FILENAME = "B-small-attempt0"
INPUTFILE = FILENAME + ".in"
OUTPUTFILE = FILENAME + ".out"
LINE_PER_CASE = 0

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
            N = int(inputfile.readline())
            return N * 2 - 1
    
    def takeInput(self, content):
        """
        content is a list of lines,
        parse the input to my variables needed
        """
        self.d = {}
        for c in content:
            this_piece = c.split()
            for num in this_piece:
                n = int(num)
                if not n in self.d:
                    self.d[n] = 1
                else:
                    self.d[n] += 1
        
        
    
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
        last_piece = []
        for n in self.d:
            if self.d[n]%2 != 0:
                last_piece.append(n)
        last_piece.sort()
        self.answer = ""
        for soldier in last_piece:
            self.answer += " " + str(soldier)
        
        
"""
-----------------------------------------------------------------
now is function time~
"""

        
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
    result = "Case #" + str(caseindex+1) + ":" + result + "\n"
    print(result)
    outputfile.write(result)
outputfile.close()   
inputfile.close()