import sys


class Logger:
    """
    Log to a file as well as the standard console
    """

    def __init__(self, filename, use_console=True):
        self.console = sys.stdout
        self.log = open(filename, 'w')
        self.use_console = use_console

    def write(self, content):
        if self.use_console: self.console.write(content)
        self.log.write(content)

    def flush(self):
        if self.use_console: self.console.flush()

problem = "B-large"
filename = "{}.in".format(problem)
sys.stdout = Logger("{}.out".format(problem))

with open(filename) as file:

    def readint():
        return int(file.readline())

    def readfloats(sep=" "):
        return list(map(float,file.readline().strip().split(sep)))

    nr_of_cases = readint()

    for case_nr in range(1,nr_of_cases+1):

        C,F,X = readfloats()

        for i in range(1000000000000):

            current_income = 2.0+i*F
            time_to_next_farm = C/current_income
            next_income = 2.0+(i+1)*F
            time_to_goal_with_next_farm = X/next_income
            toal_time_with_another_farm = time_to_next_farm + time_to_goal_with_next_farm
            time_to_goal_with_this_farm = X/current_income

            if time_to_goal_with_this_farm < toal_time_with_another_farm:

                time_before_this_farm = sum([C/(2.0+j*F) for j in range(i)])
                total_time = time_before_this_farm + time_to_goal_with_this_farm
                print("Case #{}:".format(case_nr),total_time)
                break