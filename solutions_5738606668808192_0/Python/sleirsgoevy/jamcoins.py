assert input() == '1'

divisors = '3 4 5 6 7 8 9 10 11'

n, j = map(int, input().split())

if n % 2: 
    prefix = '110'
    suffix = '11'
    l = (n - 5)//2
else:
    prefix = '1'
    suffix = '1'
    l = (n - 2)//2

print("Case #1:")

class NullCell:
    def __str__(self): return ''

class Cell:
    def __str__(self): return str(self.next)+str(self.digit)*2
    def inc(self):
        if self.digit == 0: self.digit = 1
        else:
            self.digit = 0
            self.next.inc()
    def __init__(self, prev):
        self.next = prev
        self.digit = 0

cell = NullCell()

for i in range(l): cell = Cell(cell)

for i in range(j):
    cell.inc()
    print(prefix, cell, suffix, ' ', divisors, sep='')

