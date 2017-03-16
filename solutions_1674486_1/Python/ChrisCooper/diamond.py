import sys

class ClassMap:
    def __init__(self):
        self.supers = []
        self.children = []
        self.was_hit = False

    def search_passes(self):
        if self.was_hit:
            return False
        self.was_hit = True
        passed = True
        for c in self.children:
            passed = passed and c.search_passes()
        return passed

def main():
    with open("out.txt", "w") as fout:
        with open("in.txt", "r") as fin:
            sets = int(fin.readline())
            for i in range(sets):
                fout.write("Case #%d: " % (i+1) + problem_result(fin) + "\n")
        

def problem_result(fin):
    num_classes = int(fin.readline())
    classes = []
    for i in range(num_classes):
        classes.append(get_class(fin))
    for c in classes:
        for sup in c.supers:
            classes[sup].children.append(c)
    
    for c in classes:
        if len(c.supers) == 0:
            if not c.search_passes():
                return "Yes"
            for c in classes:
                c.was_hit = False
    
    return "No"

def get_class(fin):
    c = ClassMap()
    line = fin.readline().split()
    num_supers = int(line[0])
    for i in range(1, num_supers + 1):
        c.supers.append(int(line[i])-1)
    return c


sys.setrecursionlimit(1000000)
main()
print("done")
