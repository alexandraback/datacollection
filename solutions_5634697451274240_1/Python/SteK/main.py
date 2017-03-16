class Case:
    def __init__(self, id_case, file_in, file_out):
        self.res = ""
        self.input = ""
        self.id_case = id_case
        self.read(file_in)
        self.solve()
        self.write_output(file_out)

    def read(self,file):
        self.input = file.readline()[:-1]

    def write_output(self,file):
        file.write("Case #"+str(self.id_case)+": "+str(self.res)+"\n")

    def solve(self):
        print("############ CASE : "+str(self.id_case))
        self.res = 0
        pancakes = []
        for c in self.input:
            pancakes.append(c)
        while(self.allHappy(pancakes) == False):
            ror = 0
            cpc = pancakes[0]
            while ror+1 < len(pancakes) and cpc == pancakes[ror + 1]:
                ror += 1
            for i in range(ror+1):
                if cpc == "+":
                    pancakes[i] = "-"
                else:
                    pancakes[i] = "+"
            self.res += 1

    def allHappy(self,pancakes):
        for p in pancakes:
            if p == "-":
                return False
        return True



file_in = open("B-large.in",'r')
file_out = open("data.out", 'w')
for i in range(int(file_in.readline())):
    Case(i+1,file_in,file_out)