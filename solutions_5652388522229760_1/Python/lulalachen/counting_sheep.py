class CountingSheep(object):
    """docstring for CountingSheep"""
    def __init__(self, question_index):
        super(CountingSheep, self).__init__()
        self.current_digits = set()
        self.index = 1
        self.question_index = question_index
        self.sheep_number = 0

    def is_asleep(self):
        return len(self.current_digits) >= 10

    def update_digits(self, sheep_number):
        self.sheep_number = sheep_number
        self.current_digits.update(set(str(sheep_number)))

    def log_answer(self):
        print "Case #{}: {}".format(self.question_index, self.sheep_number)

lines = int(raw_input())  # read a line with a single integer
for question_index in xrange(1, lines + 1):
    number = raw_input()
    if number == '0':
        print "Case #{}: INSOMNIA".format(question_index)
    else:
        sheep_counter = CountingSheep(question_index)
        while not sheep_counter.is_asleep():
            sheep_number = sheep_counter.index * int(number)
            sheep_counter.update_digits(sheep_number)
            sheep_counter.index += 1
        sheep_counter.log_answer()

