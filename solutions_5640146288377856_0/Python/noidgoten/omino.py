file = open("brat.in", "r")
file2 = open("brat.out", "w")

t = int(file.readline())

def run(r, c, w, t):
    file2.write("Case #" + str(t) + ": " + str(int((c-1)/w + w)*r) + "\n")


for i in range(t):
    x = file.readline().split()
    run(int(x[0]), int(x[1]), int(x[2]), i+1)