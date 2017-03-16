class Case:
    def __init__(self, id_case, file_in, file_out):
        self.res = []
        self.N = 0
        self.J = 0
        self.id_case = id_case
        self.read(file_in)
        self.solve()
        self.write_output(file_out)

    def read(self,file):
        temp = file.readline()
        temp = temp.split()
        self.N = int(temp[0])
        self.J = int(temp[1])

    def write_output(self,file):
        file.write("Case #"+str(self.id_case)+":\n")
        for s in self.res:
            file.write(s+"\n")

    def solve(self):
        current = ["1"]
        for i in range(self.N-2):
            current.append("0")
        current.append("1")
        i = 0
        while i < self.J:
            div = self.getPrime(current)
            if div != False:
                self.res.append("".join(current)+" "+" ".join(div))
                i += 1
            self.inc(current)

    def getPrime(self, jamcoin):
        jamcoin = "".join(jamcoin)
        div = []
        for base in range(2, 11):
            num = int(jamcoin, base)
            for i in range(2, int(num**(1/2))+1):
                if num % i == 0:
                    div.append(str(i))
                    break
            else:
                return False
        return div

    def inc(self, jamcoin):
        for i in range(1, len(jamcoin)-1).__reversed__():
            if jamcoin[i] == "1":
                jamcoin[i] = "0"
            else:
                jamcoin[i] = "1"
                break


file_in = open("C-test.in",'r')
file_out = open("data.out", 'w')
for i in range(int(file_in.readline())):
    Case(i+1,file_in,file_out)