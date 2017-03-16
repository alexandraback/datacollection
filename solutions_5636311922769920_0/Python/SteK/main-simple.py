class Case:
    def __init__(self, id_case, file_in, file_out):
        self.res = ""
        self.K = 0
        self.C = 0
        self.S = 0
        self.id_case = id_case
        self.read(file_in)
        self.solve()
        self.write_output(file_out)

    def read(self,file):
        input= file.readline().split()
        self.K = int(input[0])
        self.C = int(input[1])
        self.S = int(input[2])


    def write_output(self,file):
        file.write("Case #"+str(self.id_case)+": "+str(self.res)+"\n")

    def solve(self):
        print("############ CASE : "+str(self.id_case))
        self.res = ""
        first = True
        for i in range(self.K):
            if first:
                first = False
            else:
                self.res += " "
            self.res += str(i+1)



file_in = open("D-small-attempt0.in",'r')
file_out = open("data.out", 'w')
for i in range(int(file_in.readline())):
    Case(i+1,file_in,file_out)
file_out.close()
file_in.close()