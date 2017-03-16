import sys

class InputFile:
    cases = 0
    filename = ''
    lines = []
    lastLine = 1

    def __init__(self, filename):
        self.filename = filename

    def read(self):
        with open(self.filename, 'r') as f:
            self.lines = f.readlines()
        self.lines = [line.strip() for line in self.lines]
        self.cases = int(self.lines[0])

    def getCases(self):
        return self.cases

    def getNextCase(self):
        case_lines = 2*int(self.lines[self.lastLine]) - 1
        case_info = []
        start_offset = self.lastLine + 1
        end_offset = self.lastLine + case_lines + 1
        for i in range(start_offset, end_offset):
            case_info.append(self.lines[i])
        self.lastLine = self.lastLine + case_lines + 1
        return case_info


class CaseSolver:
    def __init__(self, caseNumber, caseInfo):
        self.number = caseNumber
        self.params = caseInfo

    def solve(self):
        result = ""
        count = {}
        for i in range(0, len(self.params)):
            numbers = self.params[i].split()
            for j in range(0, len(numbers)):
                key = int(numbers[j])
                if count.get(key):
                    count[key] = count[key] + 1
                else:
                    count[key] = 1
        count_items = sorted(count.items())
        for i in range(0, len(count_items)):
            (height, n) = count_items[i]
            if (n % 2 != 0):
                result = result + " " + str(height)
        # 2. Do stuff and solve the problem
        # 3. Print out the result
        return "Case #" + str(self.number) + ":" + result


if __name__ == '__main__':
    if len(sys.argv) == 2:
        # 1. Update the number of lines per case
        input_file = InputFile(sys.argv[1]);
        input_file.read()
        case_counter = 1
        while case_counter <= input_file.getCases():
            print CaseSolver(case_counter, input_file.getNextCase()).solve()
            case_counter = case_counter + 1
    else:
        usage = "Usage :"
        usage = usage + sys.argv[0]
        usage = usage + " <input_file>"
        print usage
