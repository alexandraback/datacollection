from __future__ import print_function

class IO(object):
    input_filename = "A-small-attempt0.in"

    def __init__(self):
        self.i = open("/home/toon/Downloads/{self.input_filename}".format(**locals()), 'r')
        self.output_filename = self.input_filename.split(".")[0] + ".out"
        self.o = open("/home/toon/Desktop/{self.output_filename}".format(**locals()), 'w')
        self.cases = self.parse_input()
    
    def parse_input(self):
        cases = []
        lines = self.i.readlines()
        i = 0
        n_cases = int(lines[i].strip())
        for x in range(n_cases):
            i += 1
            mote_size, n_motes = [int(n) for n in lines[i].strip().split(" ")]
            i += 1
            motes = [int(m) for m in lines[i].strip().split(" ")]
            cases.append(
                {
                    'size':mote_size,
                    'n_motes':n_motes,
                    'motes':motes})
                    
        return cases
            
    n_out = 1
    def out(self, output):
        print(
            "Case #{self.n_out}: {output}".format(**locals()),
            file = self.o)
        self.n_out += 1

io = IO()


def absorb_motes(case):
    while [m for m in case['motes'] if m < case['size']]:
        motes = case['motes'][:]
        case['motes'] = []
        for mote in motes:
            if mote < case['size']:
                case['size'] += mote
            else:
                case['motes'].append(mote)


def up(case, n_interventions):
    print("adding mote")
    print("case: ",case)
    print("n_interventions: ", n_interventions)
    case['size'] += (case['size'] - 1)
    n_interventions += 1
    return case, n_interventions

def delete(case, n_interventions):
    print("deleting all...")
    print(case, n_interventions)
    n_interventions += len(case['motes'])
    print("possible solution ", n_interventions)
    return n_interventions



for case in io.cases:
    solutions = []
    n_interventions = 0
    while case['motes']:
        if case['size'] == 1:
            solutions.append(len(case['motes']))
            break
        print(case)
        print(n_interventions)
        absorb_motes(case)
        if not case['motes']:
            print("possible solution: ", n_interventions)
            solutions.append(n_interventions)
            break
        #2 options: either delete all or 1 up
        solutions.append(delete(case, n_interventions))
        case, n_interventions = up(case, n_interventions)

    solution = min(solutions)
    io.out(solution)
        

    
    

             
         
    
