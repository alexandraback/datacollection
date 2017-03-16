
class Solve:

    def __init__(self, bff):
        self.n = len(bff) - 1
        self.used = { i : False for i in range(1, self.n + 1) }
        self.best = 0
        self.circle = self.n * [ None ]
        self.go(0)

    def check(self, length):
        circle = self.circle
        for i in range(length):
            x = circle[i]
            left = circle[length - 1] if i == 0 else circle[i - 1]
            right = circle[0] if i == length - 1 else circle[i + 1]
            if bff[x] != left and bff[x] != right:
                return False
        return True

    def go(self, length):
        if length > self.best and self.check(length):
            self.best = length
        for x in range(1, self.n + 1):
            if not self.used[x]:
                self.circle[length] = x
                self.used[x] = True
                self.go(length + 1)
                self.used[x] = False

num_cases = int(raw_input())
for case_index in range(1, num_cases + 1):
    n = int(raw_input())
    best = 0
    bff = [ None ] + list(map(int, raw_input().split()))
    result = Solve(bff).best

    print('Case #%d: %s' % (case_index, result))
