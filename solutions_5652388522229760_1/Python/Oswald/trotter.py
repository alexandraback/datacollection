def getDigits(number):
    reversedDigits = []
    while number > 0:
        reversedDigits.append(number % 10)
        number -= number % 10
        number /= 10
    reversedDigits.reverse()
    return set(reversedDigits)

def whatSee(start):
    seen = set()
    for x in range(1,101):
        current = start * x
        digits = getDigits(current)
        seen = seen.union(digits)
        if len(seen) == 10:
            return (True, x * start)
    return (False, 0)
    
def main():
    cases = int(raw_input())
    for x in range(1, cases + 1):
        number = int(raw_input())
        willSee, whatISee = whatSee(number)
        response = str(whatISee) if willSee else "INSOMNIA"
        print("Case #%s: %s" % (x, response))

main()