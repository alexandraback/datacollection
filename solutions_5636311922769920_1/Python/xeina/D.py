FILENAME = "D-large"
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
        c = content[0].split()
        self.K = int(c[0])
        self.C = int(c[1])
        self.S = int(c[2])
        
    
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
        check_list = tile_to_check(self.K, self.C, self.S)
        self.answer = ""
        if len(check_list) == 0:
            self.answer = " IMPOSSIBLE"
        
        for tile in check_list:
            self.answer += " "
            self.answer += str(tile)
        
        
        
        
        
"""
-----------------------------------------------------------------
now is function time~
"""

def tile_to_check(K, C, S):
    gold_list = make_list_of_possible_gold(K)
    tiles_to_check = []
    for student in range(S):
        if len(gold_list) == 0:
            break;
        this_check = 0
        for level in range(C):
            if len(gold_list) == 0:
                break;
            
            this_check += (level+1) * (gold_list.pop() - 1) + 1
        tiles_to_check.append(this_check)
        print(tiles_to_check)
    if len(gold_list) > 0:
        return []
    return tiles_to_check
            
        
    
def make_list_of_possible_gold(K):
    gold_list = []
    for i in range(K):
        gold_list.append(i+1)
    return gold_list

        
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