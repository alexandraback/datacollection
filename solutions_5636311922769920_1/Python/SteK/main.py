class Case:
    def __init__(self, id_case, file_in, file_out):
        self.res = []
        self.K = 0
        self.C = 0
        self.S = 0
        self.id_case = id_case
        self.read(file_in)
        self.solve()
        self.write_output(file_out)

    def read(self,file):
        input = file.readline().split()
        self.K = int(input[0])
        self.C = int(input[1])
        self.S = int(input[2])

    def write_output(self,file):
        file.write("Case #"+str(self.id_case)+": "+str(self.res)+"\n")

    def solve(self):
        print("############ CASE : "+str(self.id_case)+"############")
        if self.C * self.S < self.K:
            self.res = "IMPOSSIBLE"
        else:
            self.res = []
            connus = 0
            while connus < self.K:
                self.res.append(str(self.trouve_case(min(self.C, self.K-connus), connus)))
                connus += min(self.C, self.K-connus)
            self.res = " ".join(self.res)

    def trouve_case(self, a_trouve, connus):
        a_connaitre = connus+1
        res = a_connaitre
        for i in range(self.C-1):
            if a_connaitre < a_trouve:
                a_connaitre += 1
            res = (res-1)*self.K + a_connaitre
        return res




file_in = open("D-large.in",'r')
file_out = open("data.out", 'w')
for i in range(int(file_in.readline())):
    Case(i+1,file_in,file_out)
file_out.close()
file_in.close()