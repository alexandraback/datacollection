def minimal(scores, N):
    total = sum(scores)
    average = 2.0 * total / N

    minimals = []
    safe_scores = [s for s in scores if s >= average]
    safe_total = sum(safe_scores)
    K = len(safe_scores)

    adjusted_average = (2.0 * total - safe_total) / (N - K)

    for s in scores:
        if s >= average:
            percentage = 0.0
        else:
            percentage = (adjusted_average - s) / total
        minimals.append(percentage*100)

    return minimals

if __name__ == '__main__':
    import sys
    with open(sys.argv[1]) as input_file:
        cases = int(input_file.next())
        with open('result', 'wb') as output_file:
            for i in range(cases):
                data = [int(x) for x in input_file.next().split(' ')]
                N, scores = data[0], data[1:]
                minimals = minimal(scores, N)
                formatted_minimals = ' '.join((str(round(f, 6)) for f in minimals))
                output_file.write('Case #%d: %s\n' % (i+1, formatted_minimals))

