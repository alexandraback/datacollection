#include <cstdio>
#include <vector>

struct Point
{
    long long box_cnt;
    long long toy_cnt;
    long long result;
    bool operator==(const Point &point)
    {
        return point.box_cnt == box_cnt && point.toy_cnt == toy_cnt;
    }
};

struct Object
{
    long long cnt;
    int type;
};


Object box[101];
int box_size;
Object toy[101];
int toy_size;

void input()
{
    scanf("%d %d", &box_size, &toy_size);
    for (int i = 1; i <= box_size; i++)
        scanf("%lld %lld", &(box[i].cnt), &(box[i].type));
    for (int i = 1; i <= toy_size; i++)
        scanf("%lld %lld", &(toy[i].cnt), &(toy[i].type));
}

inline long long min(long long a, long long b)
{
	return a < b ? a : b;
}

inline long long max(long long a, long long b)
{
	return a > b ? a : b;
}

std::vector<Point> result[101][101];
long long solve(int box_m, int toy_n)
{
	if (box_m == 1)
	{
		long long cnt = 0;
		for (int i = 1; i <= toy_n; i++)
			if (toy[i].type == box[1].type)
				cnt = cnt + toy[i].cnt;
		return min(cnt, box[1].cnt);
	}
	else if (toy_n == 1)
	{
		long long cnt = 0;
		for (int i = 1; i <= box_m; i++)
			if (box[i].type == toy[1].type)
				cnt = cnt + box[i].cnt;
		return min(cnt, toy[1].cnt);
	}



	for (int i = 0; i < result[box_m][toy_n].size(); i++)
        if (result[box_m][toy_n][i].box_cnt == box[box_m].cnt &&
            result[box_m][toy_n][i].toy_cnt == toy[toy_n].cnt)
            return result[box_m][toy_n][i].result;

    if (box[box_m].type == toy[toy_n].type)
    {
        if (box[box_m].cnt > toy[toy_n].cnt)
        {
            box[box_m].cnt = box[box_m].cnt - toy[toy_n].cnt;

            Point tmp;
            tmp.box_cnt = box[box_m].cnt;
            tmp.toy_cnt = toy[toy_n].cnt;
            tmp.result = solve(box_m, toy_n-1) + toy[toy_n].cnt;
            box[box_m].cnt = box[box_m].cnt + toy[toy_n].cnt;
            result[box_m][toy_n].push_back(tmp);

			return tmp.result;
        }
        else if (box[box_m].cnt == toy[toy_n].cnt)
        {

            Point tmp;
            tmp.box_cnt = box[box_m].cnt;
            tmp.toy_cnt = toy[toy_n].cnt;
            tmp.result = solve(box_m-1, toy_n-1) + toy[toy_n].cnt;
            result[box_m][toy_n].push_back(tmp);

			return tmp.result;
        }
        else
        {
            toy[toy_n].cnt = toy[toy_n].cnt - box[box_m].cnt;

            Point tmp;
            tmp.box_cnt = toy[toy_n].cnt;
            tmp.toy_cnt = box[box_m].cnt;
            tmp.result = solve(box_m-1, toy_n) + box[box_m].cnt;
			toy[toy_n].cnt = toy[toy_n].cnt + box[box_m].cnt;
            result[box_m][toy_n].push_back(tmp);

			return tmp.result;
        }
    }
    else
    {
        Point tmp;
        tmp.box_cnt = box[box_m].cnt;
        tmp.toy_cnt = toy[toy_n].cnt;
        tmp.result = max(solve(box_m-1, toy_n), solve(box_m, toy_n-1));
        result[box_m][toy_n].push_back(tmp);
        return tmp.result;
    }
}

;

int main()
{
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
    int case_total;
    scanf("%d", &case_total);
    for (int case_i = 1; case_i <= case_total; case_i++)
    {
        input();

		for (int i = 1; i <= 100; i++)
			for (int j = 1; j <= 100; j++)
				result[i][j].clear();

        printf("Case #%d: %lld\n", case_i, solve(box_size, toy_size));
    }

    return 0;
}
