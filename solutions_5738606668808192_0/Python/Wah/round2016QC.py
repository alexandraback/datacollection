
import math

class JamCoin:
    def __init__(self, value):
        self.value = value
        self.divisors = []

    def validate(self):
        for base in range(2, 11):
            valueInBase = int(self.value, base)
            divisor = self.getDivisor(valueInBase)
            if divisor == None:
                return False
            else:
                self.divisors.append(divisor)

        return True

    def getDivisor(self, number):
        if number % 2 == 0:
            return 2
        maxdivisor = int(math.ceil(math.sqrt(number)))
        if maxdivisor > 99:
            maxdivisor = 99
        for divisor in range(3, maxdivisor, 2):
            if number % divisor == 0:
                return divisor

        return None

class TestCase:
    def __init__(self, caseIndex):
        self.caseIndex = caseIndex

    def parseInput(self):
        self.N, self.J = raw_input().split(" ")
        self.N = int(self.N)
        self.J = int(self.J)
        self.jamCoins = []

    def generateValue(self, values, value, length):
        if length == 0 or len(values) >= 5000:
            values.append(value + "1")
        else:
            self.generateValue(values, value + "0", length - 1)
            self.generateValue(values, value + "1", length - 1)

    def run(self):
        values = []
        self.generateValue(values, "1", self.N - 2)
        index = 0
        while index < len(values) and len(self.jamCoins) < self.J:
            jamCoin = JamCoin(values[index])
            index += 1
            if jamCoin.validate():
                self.jamCoins.append(jamCoin)

    def generateOutput(self):
        print "Case #%d:" % (self.caseIndex,)
        if len(self.jamCoins) == self.J:
            for jamCoin in self.jamCoins:
                print jamCoin.value, " ".join([str(x) for x in jamCoin.divisors])

for caseIndex in range(1, int(raw_input()) + 1):
    testCase = TestCase(caseIndex)
    testCase.parseInput()
    testCase.run()
    testCase.generateOutput()
