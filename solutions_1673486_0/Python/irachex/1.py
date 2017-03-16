def main(filename):
    global flag
    f = open(filename)
    ouf = open("1output.txt", "w")
    num_of_tests = int(f.readline())
    for test_i in range(num_of_tests):
        line = f.readline().split(" ")
        n = int(line[0])
        m = int(line[1])
        line = f.readline().split(" ")
        p = [0.0] + map(float, line)
        ans = float(m + 2)
        s = [1.0 for i in range(m+1)]
        for i in range(1, n + 1):
            s[i] *= s[i-1] * p[i]
        ans = min( ans, float(m-n+1) * s[n] + float(m - n + 1 + m + 1) * (1.0 - s[n]))
        for k in range(1, n+1):
            ans = min(ans, s[n-k] * float(m - n + 1 + k * 2) + (1.0 - s[n-k]) * float(m - n + 1 + k * 2 + m + 1))
        ouf.write("Case #%d: %f\n" % (test_i + 1, round(ans, 6)))

if __name__ == "__main__":
    main("test.txt")
                
        
    