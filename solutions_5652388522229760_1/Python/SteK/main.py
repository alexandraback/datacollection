class Case:
    def __init__(self, id_case, file_in, file_out):
        self.res = ""
        self.number = None
        self.id_case = id_case
        self.read(file_in)
        self.solve()
        self.write_output(file_out)

    def read(self,file):
        self.number = int(file.readline())

    def write_output(self,file):
        file.write("Case #"+str(self.id_case)+": "+str(self.res)+"\n")

    def solve(self):
        print("############ CASE : "+str(self.id_case))
        if self.number == 0:
            self.res = "INSOMNIA"
        else :
            tableau_non_vu = [i for i in range(10)]
            n_current = self.number
            while(1):
                n_list = str(n_current)
                print(n_list)
                for n in n_list:
                    if int(n) in tableau_non_vu:
                        tableau_non_vu.remove(int(n))
                if tableau_non_vu == []:
                    self.res = n_current
                    break
                n_current += self.number

file_in = open("A-large.in",'r')
file_out = open("data.out", 'w')
for i in range(int(file_in.readline())):
    Case(i+1,file_in,file_out)