class Case(object):
    def __init__(self, line):
        l = map(float, line.split())
        self.C = l[0]
        self.F = l[1]
        self.X = l[2]
        
    def solve(self):
        n = 0
        speed = 2.
        change_cost = 0
        total_cost = change_cost + self.X / speed
        while True:
            change_cost = change_cost + self.C / speed
            speed  = speed + self.F
            candidate_total_cost  = change_cost + self.X / speed
            if candidate_total_cost > total_cost:
                break
            n += 1
            total_cost = candidate_total_cost
        return total_cost


class GJ(object):
    def __init__(self, file_in = "input.txt", file_out = "output.txt"):
        self.solutions = []
        with open(file_in) as f:
            lines = f.readlines()
            self.T = int(lines[0])
            self.lines = lines[1:]
        self.process()
        self.output(file_out) 
           
    def process(self):
        for i in range(self.T):
            self.solutions.append(Case(self.lines[i]).solve())
        
    
    
    def output(self, output):
        l = map(lambda x: "Case #%d: %.7f\n"%(int(x[0])+1, x[1]), enumerate(self.solutions))
        with open(output, "w") as f:
            f.writelines(l)
            

GJ()